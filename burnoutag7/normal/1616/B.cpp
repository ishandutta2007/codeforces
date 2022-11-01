#include<bits/stdc++.h>
using namespace std;

void z_algorithm(char *s,int *z,int n){
    memset(z,0,n<<2);
    int c=0;
    for(int i=1;i<n;i++){
        if(i+z[i-c]<c+z[c]){
            z[i]=z[i-c];
        }else{
            z[i]=max(0,c+z[c]-i);
            while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
            c=i;
        }
    }
    z[0]=n;
}

int n;
char s[100005];

void mian(){
    cin>>n>>s;
    int p=n>1&&s[1]<s[0]?2:1;
    if(p==1){
        cout<<s[0]<<s[0]<<'\n';
        return;
    }
    while(p<n&&s[p]<=s[p-1])p++;
    s[p]=0;
    cout<<s;
    reverse(s,s+p);
    cout<<s<<'\n';
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