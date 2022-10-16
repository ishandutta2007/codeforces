#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string s;
	int k,i=0;
	cin>>s>>k;
	set<pair<string,int> >st;
	for(int i=0;i<s.size();i++)st.insert(make_pair(s.substr(i,1),i));
	while(st.size())
	{
		i++;
		if(i==k)
		{
			cout<<st.begin()->first;
			return 0;
		}
		pair<string,int> pr = *st.begin();
        st.erase(st.begin());
        if(pr.second < s.size()- 1) {
            pr.first += s[++pr.second];
            st.insert(pr);
        }
	}
	cout<<"No such line.";
}