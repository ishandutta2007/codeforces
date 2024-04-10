#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli dp[51][(int)2e4+1];
lli pre[51][(int)2e4+1];
lli suf[51][(int)2e4+1];
lli arr[2][(int)2e4+1];
struct node{
    int le,ri;
    lli data;
    struct node* left,*right;
    node(){
        data=0,le=0,ri=0,left=NULL,right=NULL;
    }
    int mid(){return (le+ri)/2;}
    void mt(int l, int r){
        le=l,ri=r;
        if(le!=ri){
            left=new node();
            right=new node();
            left->mt(le,mid());
            right->mt(mid()+1,ri);
        }
    }
    void update(int loc, lli val){
        if(ri<loc||le>loc)return;
        if(le==ri){
            data=val;
            return;
        }
        left->update(loc,val),right->update(loc,val);
        data=max(left->data,right->data);
    }
    lli query(int l, int r){
        if(l>ri||r<le)return LLONG_MIN;
        if(le>=l&&ri<=r)return data;
        return max(left->query(l,r),right->query(l,r));
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    node tree;
    tree.mt(0,m);
    node tree2;
    tree2.mt(0,m);
    for(int j=1;j<=m;j++){
        cin>>arr[0][j];
        arr[0][j]+=arr[0][j-1];
    }
    for(int j=1;j<=m;j++) {
        tree.update(j,pre[0][j]-arr[0][j]);
        tree2.update(j,suf[0][j]+arr[0][max(0,j-k)]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i!=n) {
                cin >> arr[1][j];
                arr[1][j] += arr[1][j - 1];
            }
            else{
                arr[1][j]=0;
            }
        }
        for(int j=k;j<=m;j++){
            dp[i][j]=max(pre[i-1][max(0,j-k)],(j+k<=m?suf[i-1][j+k]:0))+arr[1][j]-arr[1][max(0,j-k)]+arr[0][j]-arr[0][max(0,j-k)];
            if(j>=max(0,j-k+1))dp[i][j]=max(dp[i][j],tree.query(max(0,j-k+1),j)+arr[0][j]+arr[1][j]-arr[1][max(0,j-k)]);
            if(min(m,j+k)>=j+1)dp[i][j]=max(dp[i][j],tree2.query(j+1,min(m,j+k))-arr[0][max(0,j-k)]+arr[1][j]-arr[1][max(0,j-k)]);
            pre[i][j]=max(pre[i][j-1],dp[i][j]);
        }
        suf[i][m]=dp[i][m];
        for(int j=m-1;j>=0;j--){
            suf[i][j]=max(suf[i][j+1],dp[i][j]);
        }
        for(int j=1;j<=m;j++) {
            tree.update(j,pre[i][j]-arr[1][j]);
            tree2.update(j,suf[i][j]+arr[1][max(0,j-k)]);
            arr[0][j]=arr[1][j];
        }
    }
    printf("%lli\n",pre[n][m]);
    return 0;
}