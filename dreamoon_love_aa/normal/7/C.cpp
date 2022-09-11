#include<iostream>
using namespace std;
struct gcd_t{long long x,y,z;};
gcd_t gcd(long long a,long long b){
    if(!b)return (gcd_t){1,0,a};
    gcd_t t=gcd(b,a%b);
    return (gcd_t){t.y,t.x-t.y*(a/b),t.z};
}
long long abs(long long x){return x<0?-x:x;}
main(){
    bool neg=0;
    long long A,B,C;
    cin >> A >> B >> C;
    C=-C;
    if(A<0){
        A=-A;
        B=-B;
        C=-C;
    }
    if(B<0){
        neg=1;
        B=-B;
    }
    gcd_t r=gcd(A,B);
    if(neg)r.y=-r.y;
    if(C%r.z)cout << "-1\n";
    else{
        r.x*=C/r.z;
        r.y*=C/r.z;
        cout << r.x << " " << r.y << endl;
    }

}