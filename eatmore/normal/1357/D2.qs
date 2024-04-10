namespace Solution {
    open Microsoft.Quantum.MachineLearning;
    operation Solve() : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((1, [0.0, 0.75]), [ControlledRotation((0, new Int[0]), PauliY, 0), ControlledRotation((1, [0]), PauliY, 1), ControlledRotation((0, new Int[0]), PauliY, 2)], ([3.141592653589793, 1.5707963267948966, 3.141592653589793], 0.0));
    }
}