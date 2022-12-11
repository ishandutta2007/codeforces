#include<bits/stdc++.h>
using namespace std;
const int N=100;
int t,n,cnt[2],num[2];
string s;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);cnt[0]=cnt[1]=num[0]=num[1]=0;
        for(int i=1;i<=n;i++){
            cin>>s,cnt[s.size()&1]++;
            for(int j=0;j<s.size();j++)num[s[j]-'0']++;
        }
        printf("%d\n",(num[0]&1)&&!cnt[1]?n-1:n);
    }
    return 0;
}