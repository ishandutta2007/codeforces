#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m;

string t;

string str[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

struct tire {
	int next[27];
	int v;
	int fail;
};

struct ac {
	int tc;
	int root;
	tire tree[maxn];
	long long f[maxn];
	
	queue <int> q;
	
	int insert(string str){
		int i, j;
		int enow = root;
		
		for(i=0;i<str.length();i++){
			if(!tree[enow].next[str[i] - 'a']){
				tree[enow].next[str[i] - 'a'] = ++tc;
			}
			
			enow = tree[enow].next[str[i] - 'a'];
		}
		
		tree[enow].v++;
		
		return 0;
	}
	
	int init_ac(){
		int i, j;
		int enow;
		
		enow = root;
		
		tree[enow].fail = root;
		
		for(i=0;i<26;i++){
			if(tree[enow].next[i]){
				tree[tree[enow].next[i]].fail = root;
				q.push(tree[enow].next[i]);
			}
		}
		
		while(!q.empty()){
			enow = q.front();
			q.pop();
			
			for(i=0;i<26;i++){
				if(tree[enow].next[i]){
					j = tree[enow].fail;
					
					while(j > 1 and !tree[j].next[i]){
						j = tree[j].fail;
					}
					
					if(tree[j].next[i]){
						j = tree[j].next[i];
					}
					
					tree[tree[enow].next[i]].fail = j;
					tree[tree[enow].next[i]].v += tree[j].v; 
					q.push(tree[enow].next[i]);
				}
			}
			
		}
			
		return 0;
	}
	
	int find(string str){
		int i, j, k;
		j = root;
		
		for(i=0;i<str.length();i++){
			while(j > 1 and !tree[j].next[str[i] - 'a']){
				j = tree[j].fail;
			}
			
			if(tree[j].next[str[i] - 'a']){
				j = tree[j].next[str[i] - 'a'];
			}
			
			k = j;
			
			if(k > 1){
				f[i] += tree[k].v;
			}
			
			/*while(k > 1){
				if(tree[k].v){
					f[i] += tree[k].v;
				}else{
					break;
				}
				k = tree[k].fail;
			}*/
		}
		
		return 0;
	}
	
	ac(){tc = 1, root = 1;}
} treea, treeb;

int main(){
	int i, j;
	long long ans = 0;
	
	cin >> t;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> str[i];
		treea.insert(str[i]);
		reverse(str[i].begin(), str[i].end());
		treeb.insert(str[i]);
	}
	
	treea.init_ac();
	treea.find(t);
	
	reverse(t.begin(), t.end());
	treeb.init_ac();
	treeb.find(t);
	
	for(i=0;i<t.length()-1;i++){
		ans += treea.f[i] * treeb.f[(int)t.length() - i - 2];
	}
	
	cout << ans << endl;
	
	return 0;
}