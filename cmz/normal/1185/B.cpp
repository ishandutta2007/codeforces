#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; string s,t;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		cin >> s; cin >> t;
		if (s.size()>t.size()){
			printf("NO\n");
			continue;
		}
		int now1=0,now2=0,z=0;
		while (1){
			if (now1==s.size()&&now2<t.size()){
				z=1; printf("NO\n");
				break;
			}
			if (s[now1]!=t[now2]){
				z=1; printf("NO\n");
				break;
			}
			int cnt1=0,cnt2=0;
			for (int i=now1;i<s.size();++i){
				if (s[i]==s[now1]) ++cnt1; else break;
			}
			for (int i=now2;i<t.size();++i){
				if (t[i]==t[now2]) ++cnt2; else break;
			}
			if (cnt1>cnt2){
				z=1; printf("NO\n");
				break;
			}
			now1+=cnt1; now2+=cnt2; 
			if (now1==s.size()&&now2==t.size()) break;
		}
		if (z==1) continue;
		printf("YES\n");
	}
	return 0;
}