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
        let a = readInt();
        let b = readInt();
        let c = readInt();
        let nn = Math.abs(b - a);
        let n = nn * 2;
        if (n < a || n < b || n < c) {
            console.log(-1);
        }
        else {
            if (0 < c - nn && c - nn != a && c - nn != b) {
                console.log(c - nn);
            }
            else if (c + nn <= n && c + nn != a && c + nn != b) {
                console.log(c + nn);
            }
            else {
                console.log(-1);
            }
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