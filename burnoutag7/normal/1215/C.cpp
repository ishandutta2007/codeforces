#include<bits/stdc++.h>
using namespace std;

int n;
char s[200005];
char t[200005];
vector<int> sa,sb,ta,tb;
vector<int> v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>s+1;
    cin>>t+1;
    int tmp=0;
    for(int i=1;i<=n;i++){
        if(s[i]!=t[i]){
            tmp++;
            if(s[i]=='b')sb.push_back(i);
            if(s[i]=='a')sa.push_back(i);
        }
    }
    int psa=0,psb=0;
    while(psa+1<sa.size()){
        swap(s[sa[psa]],t[sa[psa+1]]);
        v.push_back(sa[psa++]);
        v.push_back(sa[psa++]);
    }
    while(psb+1<sb.size()){
        swap(s[sb[psb]],t[sb[psb+1]]);
        v.push_back(sb[psb++]);
        v.push_back(sb[psb++]);
    }
    if((sa.size()-psa-1+sb.size()-psb-1)&1){
        cout<<-1<<endl;
        return 0;
    }
    if((sa.size()-psa+sb.size()-psb)==2){
        psa=sa[psa];
        psb=sb[psb];
        if(t[1]=='a'){
            v.push_back(psb);
            v.push_back(1);
            v.push_back(1);
            v.push_back(psa);
        }else{
            v.push_back(psa);
            v.push_back(1);
            v.push_back(1);
            v.push_back(psb);
        }
    }
    cout<<v.size()/2<<endl;
    for(int i=0;i<v.size();i+=2){
        cout<<v[i]<<' '<<v[i+1]<<endl;
    }

    return 0;
}