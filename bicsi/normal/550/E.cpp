#include <iostream>
#include <cstdio>

using namespace std;
typedef int var;

bool b[1000000];

int main() {
    //freopen("debug.in", "r", stdin);
    //freopen("debug.out", "w", stdout);

    var n;
    cin>>n;
    for(var i=1; i<=n; i++) {
        cin>>b[i];
    }

    var zeros = 0;
    var i;
    for(i=n; i && b[i] == 0; i--) {
        zeros++;
    }

    if(zeros == 0) {
        cout<<"NO";
        return 0;
    }

    if(zeros >= 3) {
        cout<<"YES\n";
        for(var i=1; i<=n-3; i++) {
            cout<<b[i]<<"->";
        }
        cout<<"(0->0)->0";
        return 0;
    }
/*
    if(i == 0) {
        cout<<"YES\n";
        for(var i=1; i<n; i++) {
            cout<<"0->";
        }
        cout<<"0";
    }
*/
    if(zeros % 2 == 1) {
        cout<<"YES\n";
        for(var i=1; i<n; i++) {
            cout<<b[i]<<"->";
        }
        cout<<b[n];
        return 0;
    }

    while(i && b[i] == 1)
        i--;

    if(i == 0) {
        cout<<"NO";
        return 0;
    }

    cout<<"YES\n";
    for(var j=1; j<i; j++) {
        cout<<b[j]<<"->";
    }

    var parant = 1;
    cout<<"(0->";
    for(var j=i+1; b[j]; j++) {
        cout<<"("<<b[j]<<"->";
        parant++;
    }
    cout<<"0";
    for(var k=1; k<=parant; k++) {
        cout<<")";
    }
    cout<<"->";
    zeros--;
    for(var j=1; j<zeros; j++) {
        cout<<"0->";
    }
    cout<<"0";

    return 0;
}