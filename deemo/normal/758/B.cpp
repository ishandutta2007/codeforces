#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'R'){
			int z = i%4;
			int ans = 0;
			for (int j = z; j < s.size(); j += 4)
				if (s[j] == '!')
					ans++;
			cout << ans << " ";
			break;
		}
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'B'){
			int z = i%4;
			int ans = 0;
			for (int j = z; j < s.size(); j += 4)
				if (s[j] == '!')
					ans++;
			cout << ans << " ";
			break;
		}
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'Y'){
			int z = i%4;
			int ans = 0;
			for (int j = z; j < s.size(); j += 4)
				if (s[j] == '!')
					ans++;
			cout << ans << " ";
			break;
		}
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'G'){
			int z = i%4;
			int ans = 0;
			for (int j = z; j < s.size(); j += 4)
				if (s[j] == '!')
					ans++;
			cout << ans << "\n";
			break;
		}
	return 0;
}