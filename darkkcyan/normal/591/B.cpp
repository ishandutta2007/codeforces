#include <istream>
#include <ostream>
#include <iostream>
#include <string>

using namespace std;

//=====================
    //#define DEBUG

    #ifdef DEBUG
        #define logln(things) std::cout << things << endl;
        #define log(things) std::cout << things;
    #else
        #define logln(things)
        #define log(things)
    #endif

// Data
//====================

    // input
    int n, m;
    string inputString;

    // process
    char destToSource['z' + 1];
    char sourceToDest['z' + 1];
    istream* tempIs;

    // output
    string outputString;

// functions
//====================

    void readInput(istream& is) {
        is >> n >> m >> ws;
        getline(is, inputString);

        logln("m: " << m << ", n: " << n);
        logln("inputString: " << inputString);

        tempIs = &is;
    }

    void nextCharPair(istream& is, char& ch1, char& ch2) {
        is >> std::ws >> ch1 >> std::ws >> ch2;
    }

    void process() {
        int i;
        char k;
        char ch1, ch2, tempCh;
        for (i = 'a'; i <= 'z'; ++i) {
            destToSource[i] = i;
        }

        for (i = 0; i < m; ++i) {
            nextCharPair(*tempIs, ch1, ch2);
            logln("char pair: " << ch1 << ' ' << ch2);

            tempCh = destToSource[ch1];
            destToSource[ch1] = destToSource[ch2];
            destToSource[ch2] = tempCh;

            log("source:");
            for (k = 'a'; k <= 'z'; ++k) {
                log(k);
            }

            logln("");
            log("dest  :");
            for (k = 'a'; k <= 'z'; ++k) {
                log(destToSource[k]);
            }
            logln("\n");
        }

        for (k = 'a'; k <= 'z'; ++k) {
            sourceToDest[destToSource[k]] = k;
        }

        logln("");
        logln("final sourceToDest: ");

        for (k = 'a'; k <= 'z'; ++k) {
            log(sourceToDest[k]);
        }

        logln("");

        outputString = inputString;
        for (i = 0; i < n; ++i) {
            outputString[i] = sourceToDest[outputString[i]];
        }

    }

    void writeOutput(ostream& os) {
        logln("output " << outputString);
        os << outputString << endl;
    }


int main(void) {
    readInput(cin);
    process();
    writeOutput(cout);
}