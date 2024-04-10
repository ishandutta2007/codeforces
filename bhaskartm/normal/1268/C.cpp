#include <bits/stdc++.h>
using namespace std;

long long int n;
vector<long long int>bit;
vector<long long int>bit2;
int sum(long long int r) {
        long long int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    
   
void add(long long int idx, long long int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
    
long long int sum2(long long int r) {
        long long int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit2[r];
        return ret;
    }
    
   
void add2(long long int idx, long long int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit2[idx] += delta;
    }

int main() {
	
	cin>>n;
	bit.resize(n+1);
	bit2.resize(n+1);
	for(long long int i=0; i<=n; i++){
		bit[i]=0;
		bit2[i]=0;
	}
	long long int arr[n];
	long long int pos[n+1];
	pos[0]=0;
	for(long long int i=0; i<n; i++){
		cin>>arr[i];
		pos[arr[i]]=i;
	}
	set<long long int>s;
	set<long long int>l;
	long long int m1=-1;
	long long int m2=-1;
	long long int inv=0;
	vector<long long int>ans;

	
	for(long long int i=1; i<=n; i++){
		
		add(pos[i], 1);
		add2(pos[i], pos[i]);
		
		inv+=(i-sum(pos[i]));
		if(i==1){
			m1=pos[i];
			m2=-1;
			l.insert(pos[i]);
		}
		else if(i%2==0){
			long long int x=(*(l.begin()));
			if(pos[i]<x){
				s.insert(pos[i]);
			}
			else{
				l.erase(x);
				s.insert(x);
				l.insert(pos[i]);
			}
			auto it=s.end();
			it--;
			m1=(*it);
			m2=(*(l.begin()));
		}
		else{
			auto it=s.end();
			it--;
			long long int x=(*it);
			if(pos[i]>x){
				l.insert(pos[i]);
				m1=(*(l.begin()));
				m2=-1;
			}
			else{
				s.erase(x);
				l.insert(x);
				s.insert(pos[i]);
				m1=(*(l.begin()));
				m2=-1;
			}
		}
		
		if(i%2==1){
			long long int val=0;
			
			val=val+sum2(n-1);
			val=val-sum2(m1);
			val=val-sum2(m1-1);
			val=val-(i/2)*((i/2)+1);
			ans.push_back(inv+val);
			
		}
		else{
			long long int val=0;
			val=val+m1*((i/2)-1)-sum2(m1-1)-((i/2)*((i/2)-1))/2;
			val=val+sum2(n-1)-sum2(m2)-m2*((i/2)-1)-((i/2)*((i/2)-1))/2;
			val=val+(m2-m1-1)*(i/2);
			ans.push_back(inv+val);
			
		}
	}
	for(auto u:ans){
		cout<<u<<" ";
	}
	return 0;
}