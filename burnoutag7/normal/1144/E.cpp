#include<bits/stdc++.h>
using namespace std;

int k;
string s,t;
int tmp;
vector<int> a,b,dif,mid;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>k;
    cin>>s;
    cin>>t;
    for(int i=1;i<=k;i++){
        a.push_back(s[k-i]-'a');
        b.push_back(t[k-i]-'a');
    }
    tmp=0;
    for(int i=0;i<k;i++){
        if(b[i]-tmp>=a[i]){
            dif.push_back(b[i]-tmp-a[i]);
            tmp=0;
        }else{
            dif.push_back(26+b[i]-tmp-a[i]);
            tmp=1;
        }
    }
//    for(int i=0;i<k;i++){
//        cout<<dif[i]<<' ';
//    }cout<<endl;
    tmp=0;
    for(int i=k-1;i>=0;i--){
        dif[i]+=tmp*26;
        tmp=0;
        if(dif[i]%2)tmp=1;
        dif[i]/=2;
    }
//    for(int i=0;i<k;i++){
//        cout<<dif[i]<<' ';
//    }cout<<endl;
    tmp=0;
    for(int i=0;i<k;i++){
        mid.push_back(a[i]);
        mid[i]+=tmp;
        mid[i]+=dif[i];
        if(mid[i]>25){
            tmp=mid[i]/26;
            mid[i]%=26;
        }else{
            tmp=0;
        }
    }
    for(int i=k-1;i>=0;i--){
        cout<<char(mid[i]+'a');
    }

    return 0;
}