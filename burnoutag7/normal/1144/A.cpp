#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int a[30];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    while(n--){
        cin>>s;
        memset(a,0,sizeof(a));
        if(s.size()>26){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
        }
        int cnt=0;
        for(int i=0;i<=25;i++){
            if(a[i]>0&&a[i+1]==0)cnt++;
            if(a[i]>1){
                cnt=3;
                break;
            }
        }
        if(cnt>1){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }

    return 0;
}