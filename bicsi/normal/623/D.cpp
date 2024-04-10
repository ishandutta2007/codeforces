#include <bits/stdc++.h>

using namespace std;

double P[500], PF[500];
double Pref[500], Suff[500];

int main() {
    int n;
    double currp = 1;

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> P[i];
        P[i] /= 100;
        PF[i] = 1 - P[i];
        currp *= 1 - PF[i];
    }

    double ans = n;


    for(int i=1; i<=500000; i++) {
        double lastp = currp;

        Pref[0] = Suff[n+1] = 1;
        for(int j=1; j<=n; j++) Pref[j] = Pref[j-1] * (1 - PF[j]);
        for(int j=n; j>=1; j--) Suff[j] = Suff[j+1] * (1 - PF[j]);

        double bestp = -1; int choose = 1;
        for(int j=1; j<=n; j++) {
            double nowp = Pref[j-1] * Suff[j+1] * (1 - PF[j] * (1 - P[j]));
            if(bestp < nowp) {
                bestp = nowp;
                choose = j;
            }
        }

        currp = bestp;
        PF[choose] *= 1 - P[choose];

        ans += i * (currp - lastp);
    }

    cout << fixed << setprecision(20) << ans;
    return 0;
}