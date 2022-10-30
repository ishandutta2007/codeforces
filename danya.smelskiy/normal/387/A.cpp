#include <bits/stdc++.h>
using namespace std;
long long a,b,first,second;
char c;
int main(){
    cin>>a>>c>>b;
    first=a*60+b;
    cin>>a>>c>>b;
    second=a*60+b;
    if (second<=first) {
    if ((first-second)/60<10) cout<<"0";
    cout<<(first-second)/60<<":";
    if ((first-second)%60<10) cout<<"0";
    cout<<(first-second)%60;

    }
    else {
        second-=first;
        if ((24*60-second)/60<10) cout<<"0";
        cout<<(24*60-second)/60<<":";
        if ((24*60-second)%60<10) cout<<"0";
        cout<<(24*60-second)%60;
    }
}