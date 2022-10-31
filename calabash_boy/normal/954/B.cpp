#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
char s[maxn];
bool check(int len){
    for (int i=0;i<len;i++){
        if (s[i]!=s[i+len]){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    cin>>s;
    int maxLen =0;
    for (int len = 1;len<=n/2;len++){
        if (check(len)){
            maxLen = len;
        }
    }
    if (maxLen==0){
        cout<<n<<endl;
    }
    else{
        cout<<n-maxLen+1<<endl;
    }
    return 0;
}