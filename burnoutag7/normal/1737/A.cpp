#include<bits/stdc++.h>
using namespace std;

int n,k,a[26];

void mian(){
    cin>>n>>k;
    fill(a,a+26,0);
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        a[c-'a']++;
    }
    for(int i=0;i<k;i++){
        int m=n/k,p=-1;
        for(int i=0;i<26;i++)if(a[i]&&m){
            a[i]--;
            m--;
        }else{
            p=i;
            break;
        }
        cout<<char(p+'a');
    }
    cout<<'\n';
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