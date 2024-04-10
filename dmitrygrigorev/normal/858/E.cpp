#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#include <deque>
#define int long long
using namespace std;
bool cmp(pair<string, int> p1, pair<string, int> p2){
    if (p1.second > p2.second) return true;
    return false;
}
int32_t main(){
    srand ( time (NULL) );
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, bi;
    string ai;
    int samples = 0;
    vector<pair<string, int> > v;
    cin >> n;
    for (int i=0; i < n; i++){
        cin >> ai >> bi;
        v.push_back(make_pair(ai, bi));
        samples += bi;
    }
    sort(v.begin(), v.end(), cmp);
    set<string> free_first, free_second, rf, rs;
    int ind = -1;
    for (int i=1; i <= samples; i++){
        string ss;
        int ii = i;
        while (ii != 0){
            ss += (char) (ii%10 + '0');
            ii /= 10;
        }
        string ss1 = "";
        for (int j=ss.size() - 1; j >= 0; j--){
            ss1 += ss[j];
        }
        free_first.insert(ss1);
        rf.insert(ss1);
    }
    for (int i=samples+1; i <= n; i++){
        string ss;
        int ii = i;
        while (ii != 0){
            ss += (char) (ii%10 + '0');
            ii /= 10;
        }
        string ss1 = "";
        for (int j=ss.size() - 1; j >= 0; j--){
            ss1 += ss[j];
        }
        free_second.insert(ss1);
        rs.insert(ss1);
    }
    for (int i=0; i < samples; i++){
        if (free_second.count(v[i].first)){
            ind = i;
        }
    }
    for (int i=0; i < n; i++){
        string str = v[i].first;
        if (free_first.count(str)){
            free_first.erase(str);
        }
        if (free_second.count(str)){
            free_second.erase(str);
        }
    }
    vector<pair<string, string> > ans;
    if (free_first.size() == 0 && free_second.size() == 0){
        if (ind == -1){
            cout << 0 << endl;
            return 0;
        }
        free_second.insert(v[ind].first);
        string pps = "";
        for (int j=0; j < 6; j++){
            int rn = rand() % 26;
            pps += (char) ('a' + rn);
        }
        ans.push_back(make_pair(v[ind].first, pps));
        v[ind].first = pps;
    }
    if (free_second.size() > 0){
        vector<int> nons;
        for (int i=samples; i<n; i++){
            if (rf.count(v[i].first)){
                nons.push_back(i);
            }
        }
        for (int i=0; i < samples; i++){
            if (rf.count(v[i].first)) continue;
            if (!rs.count(v[i].first)) continue;
            if (free_first.size() != 0){
                string ff = *free_first.begin();
                free_first.erase(ff);
                if (rs.count(v[i].first)){
                    free_second.insert(v[i].first);
                }
                ans.push_back(make_pair(v[i].first, ff));
                v[i].first = ff;
                continue;
            }
            int index = nons.back();
            nons.pop_back();
            string newf = v[i].first;
            string free = *free_second.begin();
            free_second.erase(free);
            string old = v[index].first;
            ans.push_back(make_pair(v[index].first, free));
            v[index].first = free;
            ans.push_back(make_pair(newf, old));
            v[i].first = old;
            free_second.insert(newf);
        }
        for (int i=0; i < samples; i++){
            if (rf.count(v[i].first)) continue;
            if (free_first.size() != 0){
                string ff = *free_first.begin();
                free_first.erase(ff);
                if (rs.count(v[i].first)){
                    free_second.insert(v[i].first);
                }
                ans.push_back(make_pair(v[i].first, ff));
                v[i].first = ff;
                continue;
            }
            int index = nons.back();
            nons.pop_back();
            string newf = v[i].first;
            string free = *free_second.begin();
            free_second.erase(free);
            string old = v[index].first;
            ans.push_back(make_pair(v[index].first, free));
            v[index].first = free;
            ans.push_back(make_pair(newf, old));
            v[i].first = old;
        }
        for (int i=samples;i<n; i++){
            if (!rs.count(v[i].first)){
                string free = *free_second.begin();
                free_second.erase(free);
                ans.push_back(make_pair(v[i].first, free));
                v[i].first = free;
            }
        }
    }
    else{
        vector<int> nons;
        for (int i=0; i<samples; i++){
            if (rs.count(v[i].first)){
                nons.push_back(i);
            }
        }
        for (int i=samples; i < n; i++){
            if (rs.count(v[i].first)) continue;
            if (!rf.count(v[i].first)) continue;
            if (free_second.size() != 0){
                string ff = *free_second.begin();
                free_second.erase(ff);
                if (rf.count(v[i].first)){
                    free_first.insert(v[i].first);
                }
                ans.push_back(make_pair(v[i].first, ff));
                v[i].first = ff;
                continue;
            }
            int index = nons.back();
            nons.pop_back();
            string newf = v[i].first;
            string free = *free_first.begin();
            free_first.erase(free);
            string old = v[index].first;
            ans.push_back(make_pair(v[index].first, free));
            v[index].first = free;
            ans.push_back(make_pair(newf, old));
            v[i].first = old;
            free_first.insert(newf);
        }
        for (int i=samples; i < n; i++){
            if (rs.count(v[i].first)) continue;
            if (free_second.size() != 0){
                string ff = *free_second.begin();
                free_second.erase(ff);
                if (rs.count(v[i].first)){
                    free_second.insert(v[i].first);
                }
                ans.push_back(make_pair(v[i].first, ff));
                v[i].first = ff;
                continue;
            }
            int index = nons.back();
            nons.pop_back();
            string newf = v[i].first;
            string free = *free_first.begin();
            free_first.erase(free);
            string old = v[index].first;
            ans.push_back(make_pair(v[index].first, free));
            v[index].first = free;
            ans.push_back(make_pair(newf, old));
            v[i].first = old;
        }
        for (int i=0;i<samples; i++){
            if (!rf.count(v[i].first)){
                string free = *free_first.begin();
                free_first.erase(free);
                ans.push_back(make_pair(v[i].first, free));
                v[i].first = free;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i=0; i < ans.size() ;i++){
        cout << "move " << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}