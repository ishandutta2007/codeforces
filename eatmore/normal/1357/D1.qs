namespace Solution {
    open Microsoft.Quantum.MachineLearning;
    operation Solve() : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((1, [1.0, 0.0]), [ControlledRotation((1, [0]), PauliY, 0), ControlledRotation((0, new Int[0]), PauliY, 1), ControlledRotation((1, [0]), PauliY, 2)], ([1.5707963267948966, 3.141592653589793, 0.6435011087932844], 0.0));
    }
}