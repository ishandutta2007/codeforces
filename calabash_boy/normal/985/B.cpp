#include<bits/stdc++.h>
using namespace std;
const int maxn = 2005;
bitset<maxn>a[maxn];
int n,m;
char s[maxn];
int cnt[maxn];
bool check(int x){
    for (int i=0;i<m;i++){
        if(a[x][i]==1&&cnt[i]==1)return false;
    }
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%s",s);
        for (int j=0;j<m;j++){
            if (s[j]=='1'){
                a[i].set(j);
                cnt[j]++;
            }
        }
    }
    for (int i=0;i<n;i++){
        if (check(i)){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}