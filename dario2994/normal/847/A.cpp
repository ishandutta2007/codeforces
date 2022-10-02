#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int n;
    cin >> n;
    vector<int> l(n+1), r(n+1);
    vector<int> inizi;
    vector<int> coda(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        if (l[i] == 0) inizi.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (l[i] != 0) continue;
        int at = i;
        while (r[at] != 0) at = r[at];
        coda[i] = at;
    }
    
    for (int j = 0; j < (int)inizi.size()-1; j++) {
        r[coda[inizi[j]]] = inizi[j+1];
        l[inizi[j+1]] = coda[inizi[j]];
    }
    for (int i = 1; i <= n; i++) {
        cout << l[i] << " " << r[i] << "\n";
    }

}