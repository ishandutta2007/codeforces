#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	char a;
	set<int> rooms;
	for(int i=0;i<=9;i++)rooms.insert(i);
	for(int i=0;i<n;i++){
		cin>>a;
		if(a=='L'){
			rooms.erase(rooms.begin());
		}
		else if(a=='R'){
			rooms.erase(prev(rooms.end()));
		}
		else{
			rooms.insert(a-'0');
		}
	}
	for(int i=0;i<=9;i++){
		if(rooms.count(i))printf("0");
		else printf("1");
	}
	return 0;
}