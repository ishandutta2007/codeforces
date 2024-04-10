#include <bits/stdc++.h>
using namespace std;

int n;
int ans1,ans2,ans3,ans4,ans5,ans6,ans7,ans8;
inline int chek2(int x,int y,int xx,int yy){
    int res=0;
    if (ans1>=x && ans3<=xx && ans2>=y && ans4<=yy) ++res;
    if (ans5>=x && ans7<=xx && ans6>=y && ans8<=yy) ++res;
    return res;
}
inline int chek(int x,int y,int xx,int yy){
    cout<<"? "<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
    int res;
    cin>>res;
//    res=chek2(x,y,xx,yy);
    return res;
}
inline pair<pair<int,int>,pair<int,int> > good(int x,int y,int xx,int yy){
    int l=x;
    int r=xx;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (chek(mid,y,xx,yy)) l=mid;
        else r=mid;
    }
    if (chek(r,y,xx,yy)) l=r;
    x=l;
    l=x;
    r=xx;
    while (l<r-1){
        int mid=(l+r)>>1;
        if (chek(x,y,mid,yy)) r=mid;
        else l=mid;
    }
    if (chek(x,y,l,yy)) r=l;
    xx=r;
    l=y;
    r=yy;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (chek(x,mid,xx,yy)) l=mid;
        else r=mid;
    }
    if(chek(x,r,xx,yy)) l=r;
    y=l;
    l=y;
    r=yy;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (chek(x,y,xx,mid)) r=mid;
        else l=mid;
    }
    if (chek(x,y,xx,l)) r=l;
    yy=r;
    pair<pair<int,int>,pair<int,int> > res;
    res.first.first=x;
    res.first.second=y;
    res.second.first=xx;
    res.second.second=yy;
    return res;
}
inline void f1(int mid){
    pair<pair<int,int>,pair<int,int> > res;
    pair<pair<int,int>,pair<int,int> > res2;
    res=good(1,1,mid,n);
    res2=res;
    res=good(mid+1,1,n,n);
    cout<<"! "<<res2.first.first<<" "<<res2.first.second<<" "<<res2.second.first<<" "<<res2.second.second<<" ";
    cout<<res.first.first<<" "<<res.first.second<<" "<<res.second.first<<" "<<res.second.second<<endl;
    exit(0);
}
inline void f2(int mid){
    pair<pair<int,int>,pair<int,int> > res;
    pair<pair<int,int>,pair<int,int> > res2;
    res2=good(1,1,n,mid);
    res=good(1,mid+1,n,n);
    cout<<"! "<<res2.first.first<<" "<<res2.first.second<<" "<<res2.second.first<<" "<<res2.second.second<<" ";
    cout<<res.first.first<<" "<<res.first.second<<" "<<res.second.first<<" "<<res.second.second<<endl;
    exit(0);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    //cin>>ans1>>ans2>>ans3>>ans4>>ans5>>ans6>>ans7>>ans8;
    int ll=1;
    int rr=n;
    int down=1;
    int up=n;
    int l=1;
    int r=n;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (chek(1,1,mid,n)>=1) r=mid;
        else l=mid;
    }
    if (chek(1,1,l,n)>=1) r=l;
    if (r!=n && chek(1,1,r,n)==1 && chek(r+1,1,n,n)==1) f1(r);
    else {
        l=1;
        r=n;
        while (l<r-1){
            int mid=(l+r)>>1;
            if (chek(1,1,n,mid)>=1) r=mid;
            else l=mid;
        }
        if (chek(1,1,n,l)>=1) r=l;
        f2(r);
    }
}