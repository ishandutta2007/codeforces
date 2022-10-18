#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

char s[maxn],t[maxn],p[maxn];
int h1[maxn],h2[maxn];

int main(){
    ios::sync_with_stdio(0);
    int q;
    cin>>q;
    while(q--){
        cin>>s>>t>>p;
        memset(h1,0,sizeof(h1));
        memset(h2,0,sizeof(h2));
        if(strlen(t)<strlen(s)){
            cout<<"NO\n";
            continue;
        }
        for(int i=0;i<strlen(p);i++){
            h1[p[i]-'a']++;
        }
        int cp=0;
        bool ok=1;
        for(int i=0;i<strlen(t);i++){
            if(cp<strlen(s)&&s[cp]==t[i]) cp++;
            else{
                h1[t[i]-'a']--;
                if(h1[t[i]-'a']<0){
                    ok=0;
                    break;
                }
            }
        }
        if(cp!=strlen(s)) ok=0;
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}