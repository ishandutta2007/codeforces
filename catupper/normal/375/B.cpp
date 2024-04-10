#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
string str[5250];
int res, x, n, m;
int cat[5250][5250];
int main(){
    scanf("%d%d", &n, &m);
    int last;
    for(int i = 0;i < n;i++)cin >> str[i];
    for(int i = 0;i < n;i++){
	last = 0;
	for(int j = 0;j < m;j++){
	    if(str[i][j] == '1')last++;
	    else last = 0;
	    cat[j][i] = last;
	}
    }
    int res = 0;
    for(int i = 0;i < m;i++){
	
	int cnt[5001];
	memset(cnt, 0, sizeof(cnt));
	for(int j = 0;j < n;j++)cnt[cat[i][j]]++;
	int p = 0;
	for(int j = 5000;j >=0;j--){
	    while(cnt[j]){
		cnt[j]--;
		cat[i][p++] = j;
	    }
	}
	int maxima = 1 << 30;
	for(int j = 0;j < n;j++){
	    maxima = min(maxima, cat[i][j]);
	    res = max(res, maxima * (j + 1));
	}
    }
    cout << res << endl;
    return 0;
}