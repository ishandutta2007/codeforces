#include <iostream>
#include <string>

std::string S, T;
int freqS[26], freqT[26];

bool need_automaton() {
	std::string::iterator itS, itT = T.begin();
	for(itS = S.begin(); itS != S.end(); ++itS) {
		if(*itS == *itT)
			++itT;
		if(itT == T.end())
			return true;
	}
	return false;
}

bool need_array() {
	for(std::string::iterator it = S.begin(); it != S.end(); ++it) {
		++freqS[int(*it - 'a')];
	}
	for(std::string::iterator it = T.begin(); it != T.end(); ++it) {
		++freqT[int(*it - 'a')];
	}
	for(int i = 0; i < 26; ++i) {
		if(freqS[i] != freqT[i])
			return false;
	}
	return true;
}

bool need_both() {
	for(int i = 0; i < 26; ++i) {
		if(freqS[i] < freqT[i])
			return false;
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> S >> T;
	
	if(need_automaton()) {
		std::cout << "automaton";
		return 0;
	}
	if(need_array()) {
		std::cout << "array";
		return 0;
	}
	if(need_both()) {
		std::cout << "both";
		return 0;
	}
	std::cout << "need tree";
}