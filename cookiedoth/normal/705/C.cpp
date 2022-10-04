#include <iostream>

using namespace std;

int main()
{
    const int MaX1=300001;
    int m1[MaX1],m2[MaX1*2],m3[MaX1],n,q,TyPe1,x,real,k,ans,i,l,t,j;
    cin >> n >> q;
    for (i=1; i<=n; i++) {m1[i]=i; m3[i]=0;};
    for (i=1; i<=2*n; i++) {m2[i]=0;};
    k = 0;
    ans = 0;
    l = n;
    t = 0;
    for (i=1; i<=q; i++) {
        cin >> TyPe1 >> x;
        if (TyPe1==1) {
            real = m1[x];
            m2[real]++;
            k++;
            m3[k] = real;
            ans++;
        };
        if (TyPe1==2) {
            real = m1[x];
            ans = ans - m2[real];
            m2[real] = 0;
            l++;
            m1[x] = l;
        };
        if ((TyPe1==3)&&(t<x)) {
            for (j = t+1; j<=x; j++) {
                real = m3[j];
                if (m2[real]>0) {ans--; m2[real]--;};
            }
            t = x;
        };
        cout << ans << endl;
    /*    cout << "ans = " << ans << endl;
        cout << "m1 = " << m1[1] << endl;
        for (j=1; j<=10; j++) {cout << m2[j];};
        cout << endl;
        for (j=1; j<=20; j++) {cout << m3[j];};
        cout << endl; */
    }
    return 0;
}