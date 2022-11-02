#include <iostream>
#include <algorithm>
using namespace std;
unsigned n,k;
unsigned m[4];
unsigned r4,r2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    r4=n;
    r2=r4<<1;
    for(unsigned i=0;i<k;++i){
        unsigned c;
        cin>>c;
        unsigned x=c>>2;
        unsigned rm4=min(r4,x);
        r4-=rm4;
        x-=rm4;
        x<<=1;
        unsigned rm2=min(r2,x);
        r2-=rm2;
        x-=rm2;
        if(x>0){cout<<"NO"<<endl;return 0;}
        ++m[c&3];
    }
    {
        unsigned x=min(m[3],r4);
        r4-=x;
        m[3]-=x;
        if(m[3]>0){
            m[2]+=m[3];
            m[1]+=m[3];
        }
    }
    {
        unsigned x=min(m[2],r2);
        m[2]-=x;
        r2-=x;
    }
    {
        unsigned x=min(m[1],r2);
        m[1]-=x;
        r2-=x;
    }
    if(m[2]>m[1]){
        unsigned x=(m[2]-m[1])/3;
        m[2]-=x;
        m[1]+=x<<1;
    }
    if(m[2]>0||m[1]>0){
        unsigned y=min(m[2],m[1]);
        m[2]-=y;
        m[1]-=y;
        unsigned x=min(y,r4);
        r4-=x;
        y-=x;
        if(y>0){cout<<"NO"<<endl;return 0;}
    }
    if(m[2]>0){
        if(m[2]>r4){cout<<"NO"<<endl;return 0;}
    }
    else if(m[1]>0){
        if(m[1]>(r4<<1)){cout<<"NO"<<endl;return 0;}
    }
    {cout<<"YES"<<endl;return 0;}
}