#include <bits/stdc++.h>
using namespace std;
vector<int> kek;
void prefix_function (string &s) {
	int n = (int) s.length();
	kek.clear();
	kek.resize(n, 0);
	for (int i=1; i<n; ++i) {
		int j = kek[i-1];
		while (j > 0 && s[i] != s[j])
			j = kek[j-1];
		if (s[i] == s[j])  ++j;
		kek[i] = j;
	}
}
int KMP(string &txt, string &sh){
    string kok = sh+'#'+txt;
    //cout << kok << endl;
    prefix_function(kok);
    for (int i=sh.size()+1; i < kek.size(); i++) if (kek[i] == sh.size()) return i-2*sh.size();
    return -1;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> a(n), b(n);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < n; i++) cin >> b[i];
    for (int i=0; i < n; i++) if (a[i] != b[i]){
        if (i==0) break;
        swap(a[0], a[i]);
        swap(b[0], b[i]);
        break;
    }
    string A = "", B = "";
    int L = a[0].size(), R = -1;
    for (int i=0; i < a[0].size(); i++){
        if (a[0][i] != b[0][i]) {
            L = min(L, i);
            R = max(R, i);
        }
    }
    for (int i=L; i <= R; i++){
        A += a[0][i], B += b[0][i];
    }
    vector<pair<int, int> > indixes(n);
    indixes[0] = {L, R};
    for (int i=1; i < n; i++){
        int LL = a[i].size(), RR = -1;
        for (int j=0; j < a[i].size(); j++){
            if (a[i][j] != b[i][j]) {
                LL = min(LL, j);
                RR = max(RR, j);
            }
        }
        if (RR==-1){
            indixes[i] = {-1, -1};
            continue;
        }
        string aa="", bb="";
        for (int j=LL; j <= RR;j++){
            aa += a[i][j], bb += b[i][j];
        }
        if (aa!=A || bb != B){
            cout << "NO";
            return 0;
        }
        indixes[i] = {LL, RR};
    }
    while (true){
        char now = 'K';
        bool can = true;
        for (int i=0; i < n; i++){
            if (indixes[i].first == -1) continue;
            if (indixes[i].first == 0){
                can = false;
                break;
            }
            if (now == 'K') now = a[i][indixes[i].first-1];
            else if (now != a[i][indixes[i].first-1]) can = false;
        }
        if (can){
            A = now + A, B = now+B;
            for (int i=0; i < n; i++){
                if (indixes[i].first == -1) continue;
                indixes[i].first--;
            }
        }
        else break;
    }
    while (true){
        char now = 'K';
        bool can = true;
        for (int i=0; i < n; i++){
            if (indixes[i].second == -1) continue;
            if (indixes[i].second == a[i].size() - 1){
                can = false;
                break;
            }
            if (now == 'K') now = a[i][indixes[i].second+1];
            else if (now != a[i][indixes[i].second+1]) can = false;
        }
        if (can){
            A = A+now, B = B+now;
            for (int i=0; i < n; i++){
                if (indixes[i].second == -1) continue;
                indixes[i].second++;
            }
        }
        else break;
    }
    for (int i=0; i < n; i++){
        int ind = KMP(a[i], A);
        //cout << ind << endl;
        if (ind == indixes[i].first) continue;
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    cout << A  << endl;
    cout << B << endl;
}