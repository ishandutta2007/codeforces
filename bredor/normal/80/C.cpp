//  228

#include<bits/stdc++.h>
#define ll long long int
#define f first
#define s second
#define pb(x) push_back(x)
#define inf (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

using namespace std;

vector<int> v[7];

int p1,p2,p3;
int a1=INT_MAX,a2=0;

int cal(vector<int> &v1,vector<int> &v2,vector<int> &v3) {
	int m1,m2,m3;

	int a[3];

	int dif = INT_MAX;

	// cout<<v1.size()<<" "<<v2.size()<<" "<<v3.size()<<"\n";
	// cout<<p1<<" "<<p2<<" "<<p3<<"\n";

	m1 = p1/v1.size();
	m2 = p2/v2.size();
	m3 = p3/v3.size();

	// cout<<m1<<" "<<m2<<" "<<m3<<"\n";

	a[0] = m1;
	a[1] = m2;
	a[2] = m3;

	sort(a,a+3);
	dif = min(dif,a[2]-a[0]);

	m1 = p1/v1.size();
	m2 = p2/v3.size();
	m3 = p3/v2.size();

	a[0] = m1;
	a[1] = m2;
	a[2] = m3;

	sort(a,a+3);
	dif = min(dif,a[2]-a[0]);

	m1 = p1/v2.size();
	m2 = p2/v1.size();
	m3 = p3/v3.size();

	a[0] = m1;
	a[1] = m2;
	a[2] = m3;

	sort(a,a+3);
	dif = min(dif,a[2]-a[0]);

	m1 = p1/v2.size();
	m2 = p2/v3.size();
	m3 = p3/v1.size();

	a[0] = m1;
	a[1] = m2;
	a[2] = m3;

	sort(a,a+3);
	dif = min(dif,a[2]-a[0]);

	m1 = p1/v3.size();
	m2 = p2/v2.size();
	m3 = p3/v1.size();

	a[0] = m1;
	a[1] = m2;
	a[2] = m3;

	sort(a,a+3);
	dif = min(dif,a[2]-a[0]);

	m1 = p1/v3.size();
	m2 = p2/v1.size();
	m3 = p3/v2.size();

	a[0] = m1;
	a[1] = m2;
	a[2] = m3;

	sort(a,a+3);
	dif = min(dif,a[2]-a[0]);

	// cout<<dif<<"\n";

	return dif;
}

int cal1(vector<int> &v1,vector<int> &v2,vector<int> &v3) {
	int tot=0;

	map<int,int> m1,m2,m3;

	for(auto it:v1) {
		m1[it] = 1;
	}
	for(auto it:v2) {
		m2[it] = 1;
	}
	for(auto it:v3) {
		m3[it] = 1;
	}

	for(auto it:v1) {
		for(auto it1:v[it]) {
			if(m1[it1] == 1) {
				tot++;
			}
		}
	}

	for(auto it:v2) {
		for(auto it1:v[it]) {
			if(m2[it1] == 1) {
				tot++;
			}
		}
	}

	for(auto it:v3) {
		for(auto it1:v[it]) {
			if(m3[it1] == 1) {
				tot++;
			}
		}
	}

	// if(tot == 7) {
	// 	for(auto it:v1) {
	// 		cout<<it<<" ";
	// 	}
	// 	cout<<"\n";
	// 	for(auto it:v2) {
	// 		cout<<it<<" ";
	// 	}
	// 	cout<<"\n";
	// 	for(auto it:v3) {
	// 		cout<<it<<" ";
	// 	}
	// 	cout<<"\n\n";
	// }

	return tot;
}

int cal2(string s) {
	if(s == "Anka") {
		return 0;
	}
	if(s == "Chapay") {
		return 1;
	}
	if(s == "Cleo") {
		return 2;
	}
	if(s == "Troll") {
		return 3;
	}
	if(s == "Dracul") {
		return 4;
	}
	if(s == "Snowy") {
		return 5;
	}

	return 6;
}

void r1(int i,int f1[],int f2[],int f3[]) {
	if(i == 7) {
		vector<int> v1,v2,v3;

		for(int i=0;i<7;i++) {
			if(f1[i]) {
				v1.push_back(i);
			}
			if(f2[i]) {
				v2.push_back(i);
			}
			if(f3[i]) {
				v3.push_back(i);
			}
		}

		if(v1.size() == 0 || v2.size() == 0 || v3.size() == 0) {
			return;
		}

		int x1=0,x2=0;

		int dif = cal(v1,v2,v3);

		int tot = cal1(v1,v2,v3);

		if(dif<a1) {
			a1 = dif;
			a2 = tot;
		}
		else if(dif == a1) {
			a2 = max(a2,tot);
		}

		return;
	}

	f1[i] = 1;
	r1(i+1,f1,f2,f3);

	f1[i] = 0;

	f2[i] = 1;
	r1(i+1,f1,f2,f3);

	f2[i] = 0;

	f3[i] = 1;
	r1(i+1,f1,f2,f3);

	f3[i] = 0;
}

void input() {

	int n;
	cin>>n;

	string sk;

	getline(cin,sk);

	for(int i=0;i<n;i++) {

		string s;
		getline(cin,s);

		string s1,s2;
		
		int j=0;

		for(j=0;j<s.size();j++) {
			if(s[j] == ' ') {
				j++;
				break;
			}
			s1 += s[j];
		}

		for(;j<s.size();j++) {
			if(s[j] == ' ') {
				j++;
				break;
			}
		}

		for(;j<s.size();j++) {
			s2 += s[j];
		}

		// cout<<s1<<" "<<s2<<"\n";

		int k1 = cal2(s1);
		int k2 = cal2(s2);

		v[k1].push_back(k2);
	}

	// for(int i=0;i<7;i++) {
	// 	cout<<i<<"\n";
	// 	for(auto it:v[i]) {
	// 		cout<<it<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	// cout<<"\n";

	cin>>p1>>p2>>p3;

    int f1[7],f2[7],f3[7];
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    memset(f3,0,sizeof(f3));

    r1(0,f1,f2,f3);

    cout<<a1<<" "<<a2<<"\n";

}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}