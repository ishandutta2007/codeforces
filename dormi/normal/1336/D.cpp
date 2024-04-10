#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli am[101];
int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    lli trip;
    lli str;
    cin>>trip>>str;
    lli a,b;
    bool lastinc=false;
    cout<<"+ "<<1<<endl;
    cin>>trip>>str;
    cout<<"+ "<<2<<endl;
    cin>>a>>b;
    if(b>str)lastinc=true;
    else lastinc=false;
    trip=a,str=b;
    cout<<"+ "<<3<<endl;
    cin>>a>>b;
    if(a>trip){
        am[3]=(lli)sqrt(2*(a-trip))+2;
    }
    else{
        if (lastinc)am[3] = 2;
        else am[3] = 1;
    }
    lli diff=b-str;
    trip=a,str=b;
    cout<<"+ "<<1<<endl;
    cin>>a>>b;
    am[1]=(lli)sqrt(2*(a-trip))+2;
    am[2]=(b-str)/am[3];
    if(diff>(am[1]-1)*(am[2]))lastinc=true;
    else lastinc=false;
    trip=a,str=b;
    for(int i=4;i<n;i++){
        cout<<"+ "<<i<<endl;
        cin>>a>>b;
        if(a>trip){
            am[i]=(lli)sqrt(2*(a-trip))+1;
        }
        else{
            if (lastinc)am[i] = 1;
            else am[i] = 0;
        }
        am[i]++;
        if(b-str>(am[i-2])*(am[i-1]))lastinc=true;
        else lastinc=false;
        trip=a,str=b;
    }
    for(int i=3;i<n;i++){
        str-=am[i]*am[i-1]*am[i-2];
    }
    am[n]=(str/am[n-1]/am[n-2])+1;
    am[1]--;
    cout<<"! ";
    for(int i=1;i<=n;i++)cout<<am[i]-1<<" ";
    cout<<endl;
    return 0;
}