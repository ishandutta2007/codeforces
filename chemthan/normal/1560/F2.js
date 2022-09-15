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
        let n = read();
        let k = readInt();
        let d = n.length;
        function can(s) {
            used = new Array(10).fill(0);
            for (let i = 0; i < s.length; i++) {
                used[parseInt(s[i])] = 1;
            }
            let cnt = 0;
            for (let i = 0; i < 10; i++) {
                cnt += used[i];
            }
            if (k < cnt) {
                return 0;
            }
            let mx = 0;
            for (let i = 0; i < 10; i++) if (used[i]) {
                mx = Math.max(mx, i);
            }
            if (cnt < k) {
                mx = 9;
            }
            while (s.length < n.length) {
                s = s + mx;
            }
            return n <= s;
        }
        s = "";
        while (s.length < n.length) {
            let found = 0;
            for (let i = 0; i < 10; i++) {
                let s2 = s;
                s2 += i;
                if (can(s2)) {
                    s = s2;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                s = "";
                break;
            }
        }
        if (s != "") {
            console.log(s);
        }
        else {
            s = "1";
            for (let i = 0; i < n.length; i++) {
                s += "0";
            }
            console.log(s);
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