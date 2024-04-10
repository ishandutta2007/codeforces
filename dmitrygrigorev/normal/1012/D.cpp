#include <bits/stdc++.h>
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#define int long long
//#define double long double
using namespace std;
vector<pair<int, int> > ans;
bool vyh = false;
void tr(vector<pair<int, int> > &small, vector<pair<int, int> > &large, bool inv){
    pair<int, int> F = large.back();
    large.pop_back();
    pair<int, int> S = large.back();
    large.pop_back();
    pair<int, int> T = small.back();
    pair<int, int> aa = make_pair(T.second, F.second + S.second);
    if (inv) swap(aa.first, aa.second);
    small.back().second = F.second;
    small[small.size() - 2].second += S.second;
    large.back().second += T.second;
    ans.push_back(aa);
}
void normir(vector<pair<int, int> > &a, vector<pair<int, int> > &b, bool inv){
    int cut = 1;
    while (cut <= b.size()){
        int B = b.size() - cut + 1;
        int A = a.size() + cut - 1;
        if (a.size() == 1) A++;
        if (b.size() == 1) B++;
       // cout << A << " " << B << endl;
        if (abs(A-B) <= 1 && !(cut == 1 && b.size() == 1)){
            int S = 0;
        for (int j=0; j < cut; j++) S += b[b.size() - j - 1].second;
            ans.push_back(make_pair(a.back().second, S));
        if (inv){
            swap(ans.back().first, ans.back().second);
        }
            pair<int, int> p = a.back();
            a.pop_back();
            vector<pair<int, int> > rt;
            for (int i=0; i < cut-1; i++){
                pair<int, int> q = b.back();
                b.pop_back();
                rt.push_back(q);
            }
            pair<int, int> e = b.back();
            b.pop_back();
            if (a.size()) a[a.size() - 1].second += e.second;
            else a.push_back(e);
            if (b.size()) b.back().second += p.second;
            else b.push_back(p);
            reverse(rt.begin(), rt.end());
            for (int i=0; i < rt.size(); i++) a.push_back(rt[i]);
            return;
        }
        cut += 2;
    }
    cut = 1;
    while (cut <= b.size()){
        int B = b.size() - cut;
        int A = a.size() + cut;
        if (a.size() == 1) A++;
        if (b.size() == 1) B++;
        //cout << A << " " << B << endl;
        if (abs(A-B) <= 1 && !(cut == 1 && b.size() == 1)){
            int S = 0;
        for (int j=0; j < cut; j++) S += b[b.size() - j - 1].second;
            ans.push_back(make_pair(0, S));
        if (inv){
            swap(ans.back().first, ans.back().second);
        }
            vector<pair<int, int> > rt;
            for (int i=0; i < cut; i++){
                pair<int, int> q = b.back();
                b.pop_back();
                rt.push_back(q);
            }
            reverse(rt.begin(), rt.end());
            for (int i=0; i < rt.size(); i++) a.push_back(rt[i]);
            return;
        }
        cut += 2;
    }
}
void solve2(vector<pair<int, int> > &a, vector<pair<int, int> > &b){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vyh = true;
    //cout << a.size() << " " << b.size() << endl;
    if (a.size() < b.size()) normir(a, b, false);
    else if (b.size() < a.size()) normir(b, a, true);
    int S = 0;
    for (int i=0; i < a.size(); i++) S += a[i].second;
    //cout << S << endl;
    //return;
    //cout << a.size() << " " << b.size() << " " << ans.size() << endl;
    int sz = min(a.size(), b.size());
    for (int i=0; i < sz - 1; i++){
        pair<int, int> p = a.back();
        a.pop_back();
        pair<int, int> q = b.back();
        b.pop_back();
        ans.push_back(make_pair(p.second, q.second));
        a.back().second += q.second;
        b.back().second += p.second;
    }
    //cout << a.size() << " " << b.size() << " " << ans.size() << endl;
    if (a.size() == 1 && b.size() == 1) return;
    ans.push_back(make_pair(a.back().second, b.back().second));
    return;

}
void sv(vector<pair<int, int> > &a, vector<pair<int, int> > &b, bool inv){
    if (b.size() == 2){
        ans.push_back(make_pair(0, b.back().second));
        if (inv){
            swap(ans.back().first, ans.back().second);
        }
        return;
    }
    ans.push_back(make_pair(0, b.back().second));
        if (inv){
            swap(ans.back().first, ans.back().second);
        }
    ans.push_back(make_pair(a.back().second + b.back().second, b[b.size() - 2].second));
    if (inv){
            swap(ans.back().first, ans.back().second);
        }
        return;

}
void s1(vector<pair<int, int> > &a, vector<pair<int, int> > &b, bool inv){
    if (b.size() <= 3) return;
    if (b.size() % 4 == 2){
        int S = 0;
        vector<pair<int, int> > rt;
        int SS = b.size();
        for (int i=0; i <SS / 2; i++){
            rt.push_back(b.back());
            S += b.back().second;
            b.pop_back();
        }
        ans.push_back(make_pair(0, S));
        if (inv) swap(ans.back().first, ans.back().second);
        reverse(rt.begin(), rt.end());
        a.back().second += rt[0].second;
        for (int i=1; i < rt.size(); i++) a.push_back(rt[i]);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        //for (int i=0; i < a.size(); i++) cout << a[i].first << " " << a[i].second << endl;
        //cout << endl;
        //for (int i=0; i < b.size(); i++) cout << b[i].first << " " << b[i].second << endl;
        solve2(a, b);
        return;
    }
    int cut = 2;
            int S = 0;
        for (int j=0; j < cut; j++) S += b[b.size() - j - 1].second;
            ans.push_back(make_pair(a.back().second, S));
        if (inv){
            swap(ans.back().first, ans.back().second);
        }
             pair<int, int> p = a.back();
            a.pop_back();
            vector<pair<int, int> > rt;
            for (int i=0; i < cut-1; i++){
                pair<int, int> q = b.back();
                b.pop_back();
                rt.push_back(q);
            }
            pair<int, int> e = b.back();
            b.pop_back();
            if (a.size()) a[a.size() - 1].second += e.second;
            else a.push_back(e);
            if (b.size()) b.back().second += p.second;
            else b.push_back(p);
            reverse(rt.begin(), rt.end());
            for (int i=0; i < rt.size(); i++) a.push_back(rt[i]);
            return;
}
void solve1(vector<pair<int, int> > &a, vector<pair<int, int> > &b){

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.size() == 1 && b.size() == 1) return;
    if (a.size() == 1) s1(a, b, false);
    else if (b.size() == 1) s1(b, a, true);
    if (vyh) return;
    while (true){
        if ((int) min(a.size(), b.size()) < 2 || (int) max(a.size(), b.size()) == 2) break;
        if (a.size() <= b.size()) tr(a, b, false);
        else tr(b, a, true);
    }
    if (a.size() == 2 && b.size() == 2){
        ans.push_back(make_pair(a.back().second, b.back().second + b[b.size() - 2].second));
        ans.push_back(make_pair(b.back().second, 0));
        return;
    }
    if (a.size() == 1) sv(a, b, false);
    else sv(b, a, true);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    vector<pair<int, int> > a, b;
    char symb = s[0];
    int how = 1;
    for (int i=1; i < s.size(); i++){
        if (s[i] == symb) how++;
        else{
            int ind = symb - 'a';
            a.push_back(make_pair(ind, how));
            how = 1;
            symb = s[i];
        }
    }
    int ind = symb - 'a';
    a.push_back(make_pair(ind, how));
    symb = t[0];
    how = 1;
    for (int i=1; i < t.size(); i++){
        if (t[i] == symb) how++;
        else{
            int ind = symb - 'a';
            b.push_back(make_pair(ind, how));
            how = 1;
            symb = t[i];
        }
    }
    ind = symb - 'a';
    b.push_back(make_pair(ind, how));
    if (a[0].first == b[0].first){
        solve1(a, b);
    }
    else solve2(a, b);
    cout << ans.size() << endl;
    for (int i=0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}