#include<bits/stdc++.h>
using namespace std;

int n,cnt,cq;
string s;
int rp[300005];
int rq[300005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    if(n%2==1){
        cout<<":("<<endl;
        return 0;
    }
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            cnt++;
        }
        if(s[i]==')'){
            cnt--;
        }
        if(s[i]=='?'){
            cq++;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]!='?')continue;
        if(cq-cnt>=2){
            s[i]='(';
            cnt++;
        }else{
            s[i]=')';
            cnt--;
        }
        cq--;
    }
    cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            cnt++;
        }
        if(s[i]==')'){
            cnt--;
        }
        if(cnt<=0&&i!=n-1){
            cout<<":("<<endl;
            return 0;
        }
    }
    if(cnt!=0){
        cout<<":("<<endl;
        return 0;
    }
    cout<<s<<endl;

    return 0;
}