#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin >> n;
	long long int a[n],b[n];
	bool boo[n];
	vector<long long int> vec;
	long long int p,sum;
	bool t;
	sum=0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		boo[i]=false;
		for(int j=0; j<i; j++){
			if(a[i]==a[j]){
				boo[i]=true;
				if(not boo[j]){
					boo[j]=true;
				}
				if(vec.empty()) vec.push_back(a[i]);
				else{
					for(int k=0; k<vec.size(); k++){
						if(a[i]==vec.at(k)) break;
						else if(k==vec.size()-1) vec.push_back(a[i]);
					}
				}
				break;
			}
		}
	}
	for(int i=0; i<n; i++){
		cin >> b[i];
	}
	for(int i=0; i<n; i++){
		t=false;
		if(boo[i]) sum=sum+b[i];
		else{
			for(int j=0; j<vec.size(); j++){
				p=2;
				for(int k=0; k<60; k++){
					if(a[i]%p>=p/2&&vec.at(j)%p<p/2) break;
					p=p*2;
					if(p/2>max(a[i],vec.at(j))){
						sum=sum+b[i];
						t=true;
						break;
					}
				}
				if(t) break;
			}
		}
	}
	cout << sum << endl;
	return 0;
}