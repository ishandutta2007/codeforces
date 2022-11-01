#include<bits/stdc++.h>
using namespace std;

int deal(vector<int> &a,vector<int> &b){
    vector<int> suf(a.size());
    for(int i=a.size()-1,j=b.size()-1;i>=0;i--){
        while(j>=0&&b[j]>a[i])j--;
        suf[i]=j>=0?b[j]==a[i]:0;
        if(i+1<a.size())suf[i]+=suf[i+1];
    }
    int res=0;
    for(int i=0,j=0,k=0;i<b.size();i++){
        while(k<a.size()&&a[k]<=b[i]+k)k++;
        while(j<b.size()&&b[j]-b[i]+1<=k)j++;
        res=max(res,j-i+(k<a.size()?suf[k]:0));
    }
    return res;
}

void mian(){
    int n,m,t;
    cin>>n>>m;
    vector<int> ap,an,bp,bn;
    while(n--){
        cin>>t;
        if(t<0)an.emplace_back(-t);
        else ap.emplace_back(t);
    }
    while(m--){
        cin>>t;
        if(t<0)bn.emplace_back(-t);
        else bp.emplace_back(t);
    }
    reverse(an.begin(),an.end());
    reverse(bn.begin(),bn.end());
    cout<<deal(ap,bp)+deal(an,bn)<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}