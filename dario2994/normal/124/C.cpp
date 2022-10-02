#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int primes[1500];
int zrimes[1500];
int scelto=-1;
int num[26];

void crivello(){
	primes[2]=1;
	primes[3]=1;
	for(int i=4;i<1500;i++){
		primes[i]=1;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				primes[i]=0;
				break;
			}
		}
	}
	for(int i=1;i<1500;i++)zrimes[i]=primes[i]+zrimes[i-1];
}

void find(){
	int y=0;
	while(y<26 and (num[y]==0 or y==scelto))y++;
	if(y==26)y=scelto;
	cout << char('a'+y);
	num[y]--;
}

int main(){
	crivello();
	string s;
	cin >> s;
	int l=s.size();
	if(l==1 or l==2){
		cout << "YES" << endl;
		cout << s;
		return 0;
	}
	for(int i=0;i<l;i++)num[s[i]-'a']++;
	//for(int i=0;i<26;i++)cout << num[i] << " ";
	int quanti=zrimes[l]-zrimes[(l/2)]+1;
	int uguali=l-quanti;
	for(int i=0;i<26;i++)if(num[i]>=uguali)scelto=i;
	if(scelto==-1){
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	find();
	for(int i=2;i<=l/2;i++){
		cout << char('a'+scelto);
		num[scelto]--;
	}
	for(int i=(l/2)+1;i<=l;i++){
		if(primes[i])find();
		else{
			cout << char('a'+scelto);
			num[scelto]--;
		}
	}
}