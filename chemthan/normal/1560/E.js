let inputs = []

function read() {
    return inputs.pop();
}

function readInt() {
    return parseInt(read());
}

function solve() {
    let test = readInt();
    while (test--) {
        let t = read();
        used = new Array(256);
        for (let i = 0; i < 256; i++) {
            used[i] = 0;
        }
        let s = '';
        let sq = '';
        for (let i = t.length - 1; 0 <= i; i--) {
            let c = t.charCodeAt(i);
            if (!used[c]) {
                sq += t[i];
            }
            used[c] += 1;
        }
        sq = sq.split("").reverse().join("");
        cnt = new Array(256);
        for (let i = 0; i < 256; i++) {
            cnt[i] = 0;
        }
        cnt2 = new Array(256);
        for (let i = 0; i < 256; i++) {
            cnt2[i] = 0;
        }
        for (let i = 0; i < sq.length; i++) {
            let c = sq.charCodeAt(i);
            cnt[c] = parseInt(used[c] / (i + 1));
        }
        let num = 0;
        for (let i = 0; i < t.length; i++) {
            let c = t.charCodeAt(i);
            cnt2[c]++;
            if (cnt[c] == cnt2[c]) {
                num++;
            }
            s += t[i];
            if (num == sq.length) {
                break;
            }
        }
        if (s == '') {
            console.log(-1);
            continue;
        }
        for (let i = 0; i < 256; i++) {
            used[i] = 0;
        }
        let t2 = '';
        for (let i = 0; i < sq.length; i++) {
            for (let j = 0; j < s.length; j++) {
                let c = s.charCodeAt(j);
                if (!used[c]) {
                    t2 += s[j];
                }
            }
            let c = sq.charCodeAt(i);
            used[c] = 1;
        }
        if (t == t2) {
            console.log(s + ' ' + sq);
        }
        else {
            console.log(-1);
        }
    }
}

function main() {
    inputs = inputString.trim().split(/\n| /).map((string) => string.trim());
    inputs.reverse(); 
    solve();
}

let inputString = '';

process.stdin.on('data', (inputStdin) => { inputString += inputStdin; });

process.stdin.on('end', (_) => { main(); });