#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
char s[maxn];
int cnt[3];
bool used[maxn];
char other[2];
int n;
void gao2(int idx){
    if (cnt[idx] % 2 == 0)return;
    memset(used,0,sizeof used);
    int now = 0;
    for (int i=0;i<3;i++){
        if (i != idx){
            other[now++] = 'a' + i;
        }
    }
    for (int i=0;i<n;i++){
        used[i] = (s[i] == ('a' + idx));
    }
    vector<pair<int,int> > midp(0);
    pair<int,int> F = make_pair(-1,-1);
    for (int i=0;s[i] != 'a' + idx; i++){
        if (s[i] == other[0])F.first = i;
        if (s[i] == other[1])F.second = i;
    }
    midp.push_back(F);
    int temp = 0;
    while (s[temp] != 'a' + idx)temp++;
    while (temp < n){
        temp ++;
        pair<int,int> T = make_pair(-1,-1);
        while (temp < n && s[temp] != 'a' + idx){
            if (s[temp] == other[0])T.first = temp;
            if (s[temp] == other[1])T.second = temp;
            temp ++;
        }
        midp.push_back(T);
    }
    int i = 0;
    int j = midp.size() - 1;
    while (i +1< j){
        if (i == j){
            auto T = midp[i];
            if (T.first != -1)used[T.first] = 1;
            else used[T.second] = 1;
        }else{
            auto T1 = midp[i];
            auto T2 = midp[j];
            if (T1.first != -1 && T2.first != -1){
                used[T1.first] = used[T2.first] = 1;
            }else if (T1.second != -1 && T2.second != -1){
                used[T1.second] = used[T2.second] = 1;
            }
        }
        i++;
        j--;
    }
    assert(i + 1 == j);
    int L = cnt[idx] / 2;
    int templ = 0;
    int tcnt = 0;
    for (;tcnt != L;templ++){
        tcnt += s[templ] == 'a' + idx;
    }
    int R = L + 2;
    tcnt = 0;
    int tempr = 0;
    for (;tcnt != R;tempr++){
        tcnt += s[tempr] == 'a' + idx;
    }
    // cout<<templ<<" "<<tempr<<endl;
    tempr--;
    tempr--;
    for (int i = templ;i <= tempr;i ++){
        used[i] = 0;
    }
    int need = tempr - templ + 1 - 1;
    if (need %2 == 0)need --;
    int X = -1;
    for (int i=templ;i<=tempr;i++){
        if (s[i] == 'a' + idx){
            continue;
        }
        used[i] = 1;
        need --;
        if (need == 0)break;
    }
    for (int i=templ;i<=tempr;i++){
        if (s[i] == 'a' + idx)X = i;
    }
    if (s[X-1] == s[X+1]){
        for (int i=templ;i<=tempr;i++){
            used[i] = 0;
        }
        int need = tempr - templ + 1 - 2;
        if (need %2 == 0)need --;
        for (int i=templ;i<=tempr;i++){
            if (i != X && i != X-1){
                used[i] = 1;
                need --;
                if (need == 0)break;
            }
        }
    }
    int cnt = 0;
    for (int i=0;i<n;i++)cnt += used[i];
    if (cnt >= n/2){
        for (int i=0;i<n;i++){
            if (used[i]){
                putchar(s[i]);
            }
        }
        puts("");
        // cout<<idx<<endl;
        exit(0);
    }
}
void gao(int idx){
    memset(used,0,sizeof used);
    int now = 0;
    for (int i=0;i<3;i++){
        if (i != idx){
            other[now++] = 'a' + i;
        }
    }
    for (int i=0;i<n;i++){
        used[i] = (s[i] == ('a' + idx));
    }
    vector<pair<int,int> > midp(0);
    pair<int,int> F = make_pair(-1,-1);
    for (int i=0;s[i] != 'a' + idx; i++){
        if (s[i] == other[0])F.first = i;
        if (s[i] == other[1])F.second = i;
    }
    midp.push_back(F);
    int temp = 0;
    while (s[temp] != 'a' + idx)temp++;
    while (temp < n){
        temp ++;
        pair<int,int> T = make_pair(-1,-1);
        while (temp < n && s[temp] != 'a' + idx){
            if (s[temp] == other[0])T.first = temp;
            if (s[temp] == other[1])T.second = temp;
            temp ++;
        }
        midp.push_back(T);
    }
    assert(midp.size() == cnt[idx] + 1);
    int i = 0;
    int j = midp.size() - 1;
    while (i <= j){
        if (i == j){
            auto T = midp[i];
            if (T.first != -1)used[T.first] = 1;
            else used[T.second] = 1;
        }else{
            auto T1 = midp[i];
            auto T2 = midp[j];
            if (T1.first != -1 && T2.first != -1){
                used[T1.first] = used[T2.first] = 1;
            }else if (T1.second != -1 && T2.second != -1){
                used[T1.second] = used[T2.second] = 1;
            }
        }
        i++;
        j--;
    }
    if (cnt[idx] %2 == 0 && cnt[idx]){
        int L = cnt[idx] / 2;
        int templ = 0;
        int tcnt = 0;
        for (;tcnt != L;templ++){
            tcnt += s[templ] == 'a' + idx;
        }
        int R = L + 1;
        tcnt = 0;
        int tempr = 0;
        for (;tcnt != R;tempr++){
            tcnt += s[tempr] == 'a' + idx;
        }
       // cout<<templ<<" "<<tempr<<endl;
        tempr--;
        tempr--;
        for (int i=templ;i<=tempr;i++){
            used[i] = 0;
        }
        used[templ] = 1;
        for (int i=templ+1;i+ 1 <= tempr;i +=2){
            used[i] = used[i+1] = 1;
        }
    }
    int cnt = 0;
    for (int i=0;i<n;i++)cnt += used[i];
    if (cnt >= (n+1)/2){
        for (int i=0;i<n;i++){
            if (used[i]){
                putchar(s[i]);
            }
        }
        puts("");
       // cout<<idx<<endl;
        exit(0);
    }
}
int main(){
    cin>>s;
    n = strlen(s);
    if (n == 3){
        putchar(s[0]);
        puts("");
        return 0;
    }
    for (int i=0;i<n;i++){
        cnt[s[i] - 'a'] ++;
    }
    for (int idx=0;idx<3;idx++){
        gao(idx);
    }
    for (int idx = 0;idx < 3;idx ++){
        gao2(idx);
    }
    return 0;
}