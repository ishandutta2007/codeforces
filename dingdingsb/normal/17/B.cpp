#include<bits/stdc++.h>
using namespace std;
int n,m;
int q[100005];
int book[100005],mark[100005];
int min_ans[100005];
int main(){
    memset(min_ans,0x3f,sizeof min_ans);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>q[i];
    cin>>m;
    int ans=0;
    int a,b,c;
    for (int i=1;i<=m;i++){
        cin>>a>>b>>c;
        if (q[a]<=q[b]){
            cout<<-1<<endl;
            return 0;
        }
        if (book[b]){
            book[b]++;
            ans-=mark[b];
            ans+=min(mark[b],c);
            mark[b]=min(mark[b],c);
            continue;
        }
        mark[b]=c;
        ans+=c;
        book[b]++;
    }

    int sum=0;
    for (int i=1;i<=n;i++){
        if (book[i]==0){
            sum++;
        }
    }
    if (sum!=1){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans;
    return 0;
}