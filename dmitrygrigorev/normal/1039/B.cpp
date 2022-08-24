#include <bits/stdc++.h>
#define int long long
using namespace std;
bool ask(int l, int r){
    cout << l << " " << r << endl;
    string x;
    cin >> x;
    if (x=="Yes"){
        if (r==l){
            exit(0);
        }
        return true;
    }
    return false;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    int n, k;
    cin >> n >> k;
    int L = 1, R = n;
    while (true){
        while (R-L > 40){
            int mm = (L+R)/2;
            bool res = ask(L,mm);
            if (res == true){
                R=mm;
            }
            else L = mm+1;
            L-= k, R += k;
            L = max(L, (int) 1);
            R = min(R, n);
        }
        int ost = rand() % (R-L+1);
        ask(L+ost, L+ost);
        L -= k, R += k;
        L = max(L, (int) 1);
        R = min(R, n);
    }
}