#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    vector<pair<int, int> > serv;
    for (int i=0; i < n; i++){
        int X;
        cin >> X;
        serv.push_back(make_pair(X, i+1));
    }
    sort(serv.begin(), serv.end());
    for (int i=n-2; i >= 0; i--){
        int n1 = (x1 / serv[i].first) + (x1 % serv[i].first != 0);
        int rest = n - i - n1;
        if (rest > 0){
            int eat = serv[n-rest].first * rest;
            if (eat >= x2){
                cout << "Yes" << endl;
                cout << n1 << " " << rest << endl;
                for (int j=i; j < i+n1; j++) cout << serv[j].second << " ";
                cout << endl;
                for (int j=i+n1; j < n; j++) cout << serv[j].second << " ";
                cout << endl;
                return 0;
            }
        }
        int n2 = (x2 / serv[i].first) + (x2 % serv[i].first != 0);
        rest = n - i - n2;
        if (rest > 0){
            int eeat = serv[n-rest].first * rest;
            if (eeat >= x1){
                cout << "Yes" << endl;
                cout << rest << " " << n2 << endl;
                for (int j=i+n2; j < n; j++) cout << serv[j].second << " ";
                cout << endl;
                for (int j=i; j < i+n2; j++) cout << serv[j].second << " ";
                cout << endl;
                return 0;
            }
        }
    }
    cout << "No";
}