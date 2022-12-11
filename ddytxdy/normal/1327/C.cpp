#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,k;string s;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<n;i++)s+='U';for(int i=1;i<m;i++)s+='L';
    for(int i=1;i<=m;i++,i<=m?s+='R',0:0)for(int j=1;j<n;j++)s+=i&1?'D':'U';
    printf("%d\n",s.length());
    cout<<s;
    return 0;
}