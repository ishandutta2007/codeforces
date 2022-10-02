#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;


short int numero[100];

LL dinamica[100];

void dinamicizza(){
	dinamica[0]=0;
	dinamica[1]=0;
	dinamica[2]=1;
	for (int i=3; i<66; i++) {
		for (int d=1; d<i; d++){
			if (i%d) continue;
			dinamica[i]+=LL(pow(2,d-1))-dinamica[d];
		}
	}
	for (int i=1; i<66; i++) dinamica[i]+=dinamica[i-1];
}

LL f(LL n){
	LL risultato=0;
	LL salvato=n;
	vector <short int> num;
	while (n>0) {
		num.push_back(n%2);
		n/=2;
	}
	int c=num.size();
	//~ bool potenza=true;
	//~ for (int i=0; i<c-1; i++) if (num[i]==1) potenza=false;
	//~ if (potenza) return dinamica[c];
	for (int d=1; d<c; d++) {
		if (c%d) continue;
		//if(salvato==42)cout << d << " ";
		//~ vector <short int> temp;
		LL k=0;
		for(int i=c-1;i>c-d-1;i--){
			k=(2*k)+num[i];
			//~ temp.push_back(num[i]);
		}
		LL potenza=pow(2,d);
		LL h=0;
		for(int z=0;z<(c/d);z++)h=h*potenza+k;
		if(h>salvato)k--;
		//if(salvato==42)cout << k << endl;
		int e=0;
		h=k;
		while(h>0){
			e++;
			h/=2;
		}
		if(e<d)continue;
		//if(salvato==42) cout << d << endl;
		risultato+=k-pow(2,d-1)+1-f(k);
	}
	return risultato;
}

LL g(LL n){
	int c=0;
	LL salvato=n;
	while(n>0){
		c++;
		n/=2;
	}
	if(c==0)c++;
	return dinamica[c-1]+f(salvato);
}

int main(){
	dinamicizza();
	//~ for(int i=1;i<100;i++)cout << i << ": " << f(i) << endl;
	//~ f(42);
	//~ for (int i=0; i<7;i++) cout << dinamica[i] << "\n";
	LL l,r;
	cin >> l >> r;
	if(l==0)cout << g(r);
	else cout << g(r)-g(l-1);
}