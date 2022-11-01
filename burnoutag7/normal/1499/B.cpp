#include<bits/stdc++.h>
using namespace std;

int n,f,b;
char s[105];

void mian(){
    cin>>s+1;
    n=strlen(s+1);
    f=n;
    for(int i=1;i<n;i++){
        if(s[i]=='1'&&s[i+1]=='1'){
            f=i;
            break;
        }
    }
    b=1;
    for(int i=n;i>1;i--){
        if(s[i]=='0'&&s[i-1]=='0'){
            b=i;
            break;
        }
    }
    cout<<(f>=b?"yEs\n":"nO\n");
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