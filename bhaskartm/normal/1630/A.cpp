#include<bits/stdc++.h>
using namespace std;

int c(int x,int n){
    return ( x ^ ( n - 1 ) );
}

int main(){

    int tc;
    cin >> tc;
    while( tc-- ){

        int n, k;
        cin >> n >> k;

        vector<int> a(n/2), b(n/2);

        if( k == 0 ){
            for(int i=0; i<n/2; i++){
                a[i] = i;
                b[i] = c(i,n);
            }
        }

        if( k > 0 && k < n - 1 ){
            int small_k = min( k , c(k,n) );
            for(int i=0; i<n/2; i++){
                if( i != 0 || i != small_k ){
                    a[i] = i;
                    b[i] = c(i,n);
                }
            }

            a[0] = 0;
            b[0] = c(k,n);

            a[small_k] = k;
            b[small_k] = n - 1;
        }

        if( k == n - 1 ){

            if( n == 4 ){
                cout << -1 << '\n';
                continue;
            }

            a[0] = n - 2;
            b[0] = n - 1;

            a[1] = 1;
            b[1] = n - 3;

            a[2] = 0;
            b[2] = 2;

            for(int i=3; i<n/2; i++){
                a[i] = i;
                b[i] = c(i,n);
            }
        }

        for(int i=0; i<n/2; i++){
            cout << a[i] << ' ' << b[i] << '\n';
        }
    }


    return 0;
}