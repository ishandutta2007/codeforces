#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int col[205];
int cnt,mx[2];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        if(mx[0]>s[i]){
            if(mx[1]>s[i]){
                cout<<"NO"<<endl;
                return 0;
            }else{
                mx[1]=s[i];
                col[i]=1;
            }
        }else{
            mx[0]=s[i];
            col[i]=0;
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)cout<<col[i];
    cout<<endl;

    return 0;
}