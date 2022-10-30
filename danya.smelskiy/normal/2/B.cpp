#include <bits/stdc++.h>
using namespace std;


int n,x;
int posx,posy;
bool t;
pair<int,int> a[1001][1001];
pair<int,int> dp1[1001][1001],dp2[1001][1001];
pair<int,int> pred1[1001][1001],pred2[1001][1001];
inline pair<int,int> get(int x){
    pair<int,int> res=make_pair(0,0);
    while (x%2==0) {
        res.first++;
        x/=2;
    }
    while (x%5==0) {
        res.second++;
        x/=5;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cin>>x;
            if (x==0) {
                t=true;
                posx=i;
                posy=j;
                a[i][j]=make_pair(1,1);
            }else
            a[i][j]=get(x);
        }
    }
    dp1[1][1]=a[1][1];
    dp2[1][1]=a[1][1];
    for (int i=2;i<=n;++i){
        dp1[1][i]=make_pair(a[1][i].first+dp1[1][i-1].first,a[1][i].second+dp1[1][i-1].second);
        dp2[1][i]=make_pair(a[1][i].first+dp2[1][i-1].first,a[1][i].second+dp2[1][i-1].second);
        dp1[i][1]=make_pair(a[i][1].first+dp1[i-1][1].first,a[i][1].second+dp1[i-1][1].second);
        dp2[i][1]=make_pair(a[i][1].first+dp2[i-1][1].first,a[i][1].second+dp2[i-1][1].second);
        pred1[1][i]=make_pair(1,i-1);
        pred2[1][i]=make_pair(1,i-1);
        pred1[i][1]=make_pair(i-1,1);
        pred2[i][1]=make_pair(i-1,1);
    }
    for (int i=2;i<=n;++i){
        for (int j=2;j<=n;++j){
            if (dp1[i-1][j].first<dp1[i][j-1].first || (dp1[i-1][j].first==dp1[i][j-1].first && dp1[i-1][j].second<dp1[i][j-1].second))  {
                dp1[i][j]=make_pair(dp1[i-1][j].first+a[i][j].first,dp1[i-1][j].second+a[i][j].second);
                pred1[i][j]=make_pair(i-1,j);
            } else {
                dp1[i][j]=make_pair(dp1[i][j-1].first+a[i][j].first,dp1[i][j-1].second+a[i][j].second);
                pred1[i][j]=make_pair(i,j-1);
            }
            if (dp2[i-1][j].second<dp2[i][j-1].second || (dp2[i-1][j].second==dp2[i][j-1].second && dp2[i-1][j].first<dp2[i][j-1].first))  {
                dp2[i][j]=make_pair(dp2[i-1][j].first+a[i][j].first,dp2[i-1][j].second+a[i][j].second);
                pred2[i][j]=make_pair(i-1,j);
            } else {
                dp2[i][j]=make_pair(dp2[i][j-1].first+a[i][j].first,dp2[i][j-1].second+a[i][j].second);
                pred2[i][j]=make_pair(i,j-1);
            }
        }
    }
    int q=min(dp1[n][n].first,dp1[n][n].second);
    q=min(q,min(dp2[n][n].first,dp2[n][n].second));
    if (t==true && q!=0) {
        cout<<1<<'\n';
        for (int i=1;i<posx;++i)
            cout<<"D";
        for (int i=1;i<n;++i)
            cout<<"R";
        for (int i=posx+1;i<=n;++i)
            cout<<"D";
        return 0;
    }
    cout<<q<<'\n';
    string ans="";
    int x=n;
    int y=n;
    while ((x>1 || y>1)) {
        pair<int,int> to;
        if (min(dp1[n][n].first,dp1[n][n].second)<=min(dp2[n][n].first,dp2[n][n].second)) to=pred1[x][y];
        else to=pred2[x][y];
        if (to.first!=x && to.first!=0) ans="D"+ans;
        else ans="R"+ans;
        x=to.first;
        y=to.second;
    }
    cout<<ans;
}