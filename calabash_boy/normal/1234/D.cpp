#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
inline int lowbit(int x){
    return x & -x;
}
struct BIT{
    int sum[maxn];
    void add(int x,int del){
        while (x<maxn){
            sum[x] += del;
            x += lowbit(x);
        }
    }
    int query(int x){
        int ret = 0;
        while (x){
            ret += sum[x];
            x -= lowbit(x);
        }
        return ret;
    }
    int query(int l,int r){
        return query(r) - query(l-1);
    }
}sum[26];
char s[maxn];
int main(){
    cin>>s+1;
    int q;
    cin>>q;
    int n = strlen(s+1);
    for (int i=1;i<=n;i++){
        int ch = s[i] - 'a';
        sum[ch].add(i, 1);
    }
    while (q--){
        int op;
        cin>>op;
        if (op == 1){
            static char temp[5];
            int pos;
            cin>>pos>>temp;
            sum[s[pos] - 'a'].add(pos, -1);
            sum[temp[0] - 'a'].add(pos, 1);
            s[pos] = temp[0];
        }else{
            int l,r;
            cin>>l>>r;
            int ans = 0;
            for (int i=0;i<26;i++){
                ans += !!sum[i].query(l,r);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}