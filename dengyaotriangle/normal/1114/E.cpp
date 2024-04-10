#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int ab(int n){return (n<0?-n:n);}
vector<int> v;
int main(){
    int l=0,r=1000000000;
    int tm=60;
    int n;
    cin>>n;
    while(r-l>1){
        int m=(l+r)>>1;
        cout<<"> "<<m<<endl;
        bool ans;cin>>ans;
        tm--;
        if(ans){
            l=m;
        }else r=m;
    }
    int mxv;
    for(int i=r;;i--){
        cout<<"> "<<i<<endl;
        bool ans;cin>>ans;
        tm--;
        if(ans){
            mxv=i+1;
            break;
        }
    }
    srand(time(0));
    int g=0;
    while(tm--){
        int q=((rand()<<10)^rand())%(n)+1;
        cout<<"? "<<q<<endl;
        int r;cin>>r;
        v.push_back(r);
    }
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++) g=gcd(g,ab(v[i]-v[j]));
    }
    cout<<"! "<<mxv-(n-1)*g<<' '<<g;
    return 0;
}