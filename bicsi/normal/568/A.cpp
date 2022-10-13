#include <bits/stdc++.h>

using namespace std;
typedef int var;


bool P[10000000];

vector<var> Cifs;
bool pal(int n) {
    Cifs.clear();
    while(n) {
        Cifs.push_back(n%10);
        n /= 10;
    }

    int x = Cifs.size();
    for(int i=0, j=x-1; i<j; i++, j--)
        if(Cifs[i] != Cifs[j])
        return 0;
    return 1;
}

void ciur(int MAX) {
    P[0] = P[1] = 1;
    for(int i=2; i<=MAX; i++) {
        if(!P[i]) {
            for(int j=i*2; j<=MAX; j+=i)
                P[j] = 1;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ciur(1500000);

    // cerr << pal(44);

    int primes = 0, pals = 0, p, q;
    cin>>p>>q;
    int i, a;
    int maxx = 0;
    for(i=1;i <= 2000000; i++) {

        if(pal(i)) pals++;
        if(!P[i]) primes++;
        if(1LL*primes*q <= 1LL*pals*p) maxx = i;
    }
/*
    for(int i=1; i<=40; i++) {
        if(!P[i]) cerr << i << " ";
    }
    cerr << endl;
    for(int i=1; i<=40; i++) {
        if(pal(i)) cerr << i << " ";
    }
*/
    cout<<maxx;


    return 0;
}