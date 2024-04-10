#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;
char s[maxn];
int n;
int main(){
    cin>>s;
    n = strlen(s);
    int i=0;
    for (;i<n&&s[i]!='b';i++);
    if (i==n){
        cout<<"NO"<<endl;
        return 0;
    }
    int j=n-1;
    for (;j>=0&&s[j]!='b';j--);
    for (int k =i;k<=j;k++){
        if (s[k]!='b'){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for (int k=0;k<i;k++){
        if (s[k]!='a'){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for (int k=j+1;k<n;k++){
        if(s[k]!='c'){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    int cnta = i;
    int cntb = j-i+1;
    int cntc = n-j-1;
    if (1LL*cnta*cntb*cntc==0||(cntc!=cnta&&cntc!=cntb)){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    return 0;
}