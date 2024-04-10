#include <bits/stdc++.h>
using namespace std;
const int maxn = 610000;
char A[maxn];
int main(){
	scanf("%s", A);
	int n = strlen(A);
	vector<pair<int, int> > vec;
	for (int i = 0; i < n; ++i){
        int ch = A[i];
        if (vec.empty() || ch != vec.back().first)
            vec.emplace_back(ch, 1);
        else
            vec.back().second += 1;
	}
	int m = vec.size() / 2;
	if (vec.size() % 2 == 0){
        puts("0");
        return 0;
	}
	if (vec[m].second < 2) {
        puts("0");
        return 0;
	}
	bool ok = true;
	for (int i = 1; i <= m; ++i){
        if (vec[m+i].first != vec[m-i].first)
            ok = false;
        if (vec[m+i].second + vec[m-i].second < 3){
            ok = false;
        }
    }
	if (!ok){
        puts("0");
        return 0;
	}
	printf("%d\n", vec[m].second + 1);
	return 0;
}