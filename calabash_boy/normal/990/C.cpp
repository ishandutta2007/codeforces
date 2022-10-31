//
// Created by calabash_boy on 18-6-11.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 3e5+100;
int preffix[maxn],suffix[maxn];
int n;
int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cin>>n;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        int lft=0,rft=0,Min=0x3f3f3f3f;
        for (int j=0,tempSum=0;j<s.size();j++){
            lft+=s[j]=='(';
            rft+=s[j]==')';
            tempSum+=(s[j]==')'?-1:1);
            Min = min(Min,tempSum);
        }
        if(lft>=rft&&Min>=0){
            preffix[lft-rft]++;
        }
        if(rft>=lft&&Min>=lft-rft){
            suffix[rft-lft]++;
        }
    }
    LL ans =0;
    for (int i=0;i<maxn;i++){
        ans+=1LL*preffix[i]*suffix[i];
    }
//    cout<<preffix[0]<<" "<<preffix[1]<<endl;
//    cout<<suffix[0]<<" "<<suffix[1]<<endl;
    cout<<ans<<endl;
    return 0;
}