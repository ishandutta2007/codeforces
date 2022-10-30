#include <bits/stdc++.h>
using namespace std;

int w, n, k;
bool p; string s;

int vel(){
    long long x=rand(), y=rand(), z=rand();
    return (x*y+z)%n+1;
}

void val(int a){
    cout << "! " << a << endl;
}

bool ek(int a){
    cout << "? " << 1 << " " << 1 << endl << 1 << endl << a << endl;
    cin >> s; return s[0]=='S';
}

bool mk(int a, int b) {
    cout << "? " << a << " " << a << endl;
    for (int i=b-a; i<b; i++) cout << i << " ";
    cout << endl;
    for (int i=b; i<b+a; i++) cout << i << " ";
    cout << endl;
    cin >> s; return s[0]=='F';
}

int main(){
    cin >> w;
    while(w--){
        cin >> n >> k, p=0;
        for (int i=1; i<=28; i++){
            int a=vel();
            if (!p && a!=1) if (ek(a)) val(1), p=1;
        }
        if (!p){
            int l=1, h=n;
            while(h-l>1){
                int m=min((h+l)/2, 2*l);
                if (mk(m-l, l+1)) h=m;
                else l=m;
            }
            val(h);
        }
    }
}