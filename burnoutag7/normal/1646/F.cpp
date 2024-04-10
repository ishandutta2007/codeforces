#include<bits/stdc++.h>
using namespace std;

int n,c[105][105],ans[105*105][105],tot;
bool dif[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int card;
            cin>>card;
            c[i][card]++;
        }
        dif[i]=*min_element(c[i]+1,c[i]+1+n)==1;
    }
    while(!*min_element(dif,dif+n)){
        ++tot;
        int id;
        for(int i=0;i<n;i++)if(!dif[i]){
            ans[tot][i]=max_element(c[i]+1,c[i]+1+n)-c[i];
            id=i;
        }
        for(int i=(id+1)%n;i!=id;i=(i+1)%n)if(dif[i]){
            ans[tot][i]=ans[tot][(i-1+n)%n];
        }
        for(int i=0;i<n;i++)if(!dif[i]){
            c[i][ans[tot][i]]--;
            c[i][ans[tot][(i-1+n)%n]]++;
            dif[i]=*min_element(c[i]+1,c[i]+1+n)==1;
        }
    }
    for(int i=0;i<n;i++){
        int rd=tot;
        for(int j=1;j<n;j++){
            int val=(i+j)%n+1;
            for(int k=0;k<j;k++)ans[++rd][(i+k)%n]=val;
        }
    }
    tot+=n*(n-1)/2;
    cout<<tot<<'\n';
    for(int i=1;i<=tot;i++){
        for(int j=0;j<n;j++)cout<<ans[i][j]<<' ';
        cout<<'\n';
    }

    return 0;
}