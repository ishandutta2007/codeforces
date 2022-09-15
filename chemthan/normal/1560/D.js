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
        let res = 100;
        let p2 = BigInt(1);
        for (let i = 0; i < 100; i++) {
            let s2 = p2.toString();
            let cost = 0;
            let ptr = 0;
            for (let i = 0; i < s2.length; i++) {
                while (ptr < n.length && n[ptr] != s2[i]) {
                    cost++;
                    ptr++;
                }
                if (ptr < n.length && n[ptr] == s2[i]) {
                    ptr++;
                }
                else {
                    cost++;
                }
            }
            cost += n.length - ptr;
            res = Math.min(res, cost);
            p2 = p2 * BigInt(2);
        }
        console.log(res);
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