#include <bits/stdc++.h>

using namespace std;

int V[500000], Work[500000], I[500000], Ans[500000];

void DoImpar(int V[], int n) {
    Work[0] = V[0]; Work[n - 1] = V[n - 1];
    for (int i = 1; i < n - 1; ++i) {
        if (V[i] >= V[i - 1] && V[i] >= V[i + 1])
            Work[i] = max(V[i - 1], V[i + 1]);
        else Work[i] = V[i];
    }

    for (int i = 0; i < n; ++i)
        I[i] = i;

    sort(I, I + n, [](int a, int b) {
        return Work[a] > Work[b];
    });

    int k = n - 1;
    if ((n - k) % 2 == 0) --k;
    cerr << "Start: " << k << endl;

    for (int i = 0; i < n; ++i) {
        int now = I[i];

        while(k >= 0) {
            bool ok = true;
            int half = (n - k) / 2;

            if (now - half < 0 || now + half >= n)
                break;

            Ans[k] = Work[now];
            k -= 2;
        }
    }
}

int VV[500000];
void DoPar(int V[], int n) {
    if (n == 1) return;
    for (int i = 0; i < n - 1; ++i)
        VV[i] = max(V[i], V[i + 1]);
    DoImpar(VV, n - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }

    DoImpar(V, n);
    DoPar(V, n);

    for (int i = 0; i < n; ++i) Ans[n - 1] = max(Ans[n - 1], V[i]);
    if (n > 1) Ans[n - 2] = Ans[n - 1];

    for (int i = 0; i < n; ++i)
        cout << Ans[i] << ' ';
    cout << endl;

	
	return 0;
}