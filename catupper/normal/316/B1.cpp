#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int xpos;
int n, x;
vector<int> lens;
int head[1050], back[1050], dp[1050];
int main(){
    cin >> n >> x;
    for(int i = 1;i <= n;i++){
	cin >> head[i];
	back[head[i]] = i;
    }
    for(int i = 1;i <= n;i++){
	if(head[i])continue;
	int len = 1;
	int j = i;
	while(back[j] && len){
	    if(j == x){
		xpos = len;
		len = 0;
		break;
	    }
	    len++;
	    j = back[j];
	}
	if(j == x && len){xpos = len;len = 0;}
	if(len)lens.push_back(len);
    }
    dp[0] = 1;
    for(int i = 0;i < lens.size();i++){
	for(int j = n + 1;j - lens[i] >= 0;j--){
	    dp[j] |= dp[j - lens[i]];
	}
    }
    for(int i = 0;i <= n + 1;i++){
	if(dp[i] && i + xpos)cout << i + xpos << endl;
    }
    return 0;
}